 inherit ITEM;
void create()
{
        set_name("̴ľ�㼸", ({ "desk", "̴ľ�㼸" , "�㼸", "��"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("prep", "on");
                set("long", "һ��̴ľ�㼸\n");
                set("value", 1);
        }
    
} 
int is_container() { return 1; }     
