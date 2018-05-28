local root_table = {};
root_table.string = "root_str"
root_table.int = 123;

local inner_table = {};
inner_table.string =  "inner_str";
inner_table.int = 456;

table.insert(root_table, inner_table);

getLuaTable(root_table);
