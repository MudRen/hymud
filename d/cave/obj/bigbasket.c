 inherit ITEM;
void create()
{
    set_name("�����", ({ "big basket","basket"}) );
        set_weight(1000);
    set_max_encumbrance(20000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "��");
        set("long", "һ���ֹ����ƵĴ����\n");
        set("value", 5000);
        }
        
} 
int is_container() { return 1; }  
