inherit ITEM;
void create()
{
    set_name("蒲包", ({ "pu bao", "bag" }));
    set_weight(180);
    set("long", @LONG
蒲草是楚州的特产，而利用蒲草进行编织，也是楚州所特有的一种手工业，蒲包
就是其中的一种重要的产品，楚州人多用它来装东西，很方便。
LONG
    );
    set_max_encumbrance(12000);
    if (clonep())
        set_default_object(__FILE__);
    else 
    {
        set("unit", "只");
        set("value", 27);
    }
}

int is_container() { return 1; }
