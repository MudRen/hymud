 inherit ITEM;
void create()
{
        set_name("��ʯ", ({ "suishi", "��ʯ", "stone", "sui shi" }) );
        set_weight(1500);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ʯͷ����ֵ��ǣ������������������ˮ����
��Ҫ�Ҹ���������ĵط����������������������\n");
                set("value", 1);
                set("no_drop",1);
                set("no_give",1);
        }
        
} 
void init() {
        if (this_player() == environment() ) {
                add_action("do_burn", "burn");
        }
} 
int do_burn(string arg) {
        
        if( arg != "suishi" ) return notify_fail("��Ҫ��ʲô��\n");
        environment(this_player())->burn_notify(this_object(), 0);
        return 1;
}        
