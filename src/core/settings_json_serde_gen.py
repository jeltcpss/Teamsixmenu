import re

# Usage: cmd line -> python ./settings_json_serde_gen.py > output.txt

def find_differences(list1, list2):
    list2_set = set(list2)
    list_1_items_missing_in_list_2 = [x for x in list1 if x not in list2_set]
    if len(list_1_items_missing_in_list_2) > 0:
        print(list1)
        print(list2)
        print("items missing in vanilla:")
        print(list_1_items_missing_in_list_2)
        print()


lines = open(
    "./settings.hpp",
    "r",
).readlines()


class Field:
    def __init__(self, name, ignore_flag, generator_ignore_flag, line_number):
        self.name = name
        self.ignore_flag = ignore_flag
        self.generator_ignore_flag = generator_ignore_flag
        self.line_number = line_number


class Struct:
    def __init__(self, name, fields=None):
        self.name = name
        self.fields = []


vanilla_yimmenu_serde = []
all_fields_serializers = []

struct_stack = []
struct_name_to_struct = dict()

ignore_flag = False
generator_ignore_flag = False
line_number = 0
for line in lines:
    line_number += 1
    line = line.strip()

    if line.startswith("struct") or line.startswith("class") and ";" not in line:
        struct_name = line.split()[1].strip()
        new_struct_name = ""
        if len(struct_stack) > 0:
            new_struct_name += struct_stack[0].name + "::"
        struct_name = new_struct_name + struct_name
        cur_struct = Struct(struct_name)
        struct_name_to_struct[struct_name] = cur_struct
        struct_stack.insert(0, cur_struct)
        continue

    is_inline_struct_var_definition = line.startswith("} ") and line.endswith("{};")
    if is_inline_struct_var_definition:
        struct_stack.pop(0)
    elif line == "};":
        struct_stack.pop(0)
        continue

    if len(struct_stack) > 0:
        if line == "// Json Parser: Ignore":
            ignore_flag = True
            continue

        if line == "// Json Parser: Generator Ignore":
            generator_ignore_flag = True
            continue

        # if "NLOHMANN_DEFINE_" in line:
        #     vanilla_yim_serde = (
        #         line.split(";")[0].split("(")[1].replace(")", "").split(",")
        #     )
        #     vanilla_yim_serde = list(map(lambda x: x.strip(), vanilla_yim_serde))
        #     vanilla_yim_serde = (vanilla_yim_serde[0], sorted(vanilla_yim_serde[1:]))
        #     vanilla_yimmenu_serde.append(vanilla_yim_serde)

        if ";" not in line:
            continue

        potential_func_hint_1 = line.find("(")
        potential_func_hint_2 = line.find("const")
        potential_func_hint_3 = line.find("();")
        if potential_func_hint_1 != -1 and potential_func_hint_2 != -1:
            # print(line)
            continue
        if potential_func_hint_3 != -1:
            # print(line)
            continue

        if "*" in line and "const char" not in line:
            continue

        parts = line.split("=")[0].split("{")[0].split("[")[0].split(";")[0].split()
        # print(parts)
        field_name = parts[-1]
        # print(field_name)

        struct_stack[0].fields.append(
            Field(field_name, ignore_flag, generator_ignore_flag, line_number)
        )
        # if generator_ignore_flag:
        #     print(field_name)
        ignore_flag = False
        generator_ignore_flag = False


print("namespace big")
print("{")
print("//#define SERIALIZE_EVERYTHING")
print("#ifdef SERIALIZE_EVERYTHING")

vanilla_yimmenu_serde = sorted(vanilla_yimmenu_serde, key=lambda x: x[0])

# Generate nlohmann json macros
for struct_name, struct in reversed(struct_name_to_struct.items()):
    cpp_code = f"\tNLOHMANN_DEFINE_TYPE_NON_INTRUSIVE({struct_name}, "
    # cpp_code = f"\tNLOHMANN_DEFINE_TYPE_INTRUSIVE({struct_name}, "

    added_any_field = False
    for field in struct.fields:
        if not field.generator_ignore_flag:
            cpp_code += f"{field.name}, "
            added_any_field = True

    if not added_any_field:
        continue

    cpp_code = cpp_code[:-2]

    cpp_code += ")"

    print(cpp_code)

    # all_field_serde = cpp_code.split("(")[1].replace(")", "").split(",")
    # all_field_serde = list(map(lambda x: x.strip(), all_field_serde))
    # all_field_serde = (all_field_serde[0], sorted(all_field_serde[1:]))
    # all_fields_serializers.append(all_field_serde)

# all_fields_serializers = sorted(all_fields_serializers, key=lambda x: x[0])

# for i in range(0, len(all_fields_serializers)):
#     find_differences(all_fields_serializers[i][1], vanilla_yimmenu_serde[i][1])

print("#else")

# Generate nlohmann json macros
for struct_name, struct in reversed(struct_name_to_struct.items()):
    cpp_code = f"\tNLOHMANN_DEFINE_TYPE_NON_INTRUSIVE({struct_name}, "
    # cpp_code = f"\tNLOHMANN_DEFINE_TYPE_INTRUSIVE({struct_name}, "

    added_any_field = False
    for field in struct.fields:
        if not field.generator_ignore_flag and not field.ignore_flag:
            cpp_code += f"{field.name}, "
            added_any_field = True

    if not added_any_field:
        continue

    cpp_code = cpp_code[:-2]

    cpp_code += ")"

    print(cpp_code)

print("#endif")
print("}")
