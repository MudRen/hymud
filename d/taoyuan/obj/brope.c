 inherit ITEM;
void create()
{
    set_name("������", ({ "rope" }) );
    set_weight(10000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "��ɫ�����������������͵Ĺ���\n");
        set("value", 0);
    }
    
} 
void init() {
        add_action("do_use", "tie");
} 
int do_use(string arg)
{
//        if( arg != "fish pole" ) return 0; 
        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "��\n");
        environment(this_player())->tie_notify(this_object(), 0); 
        return 1;
}      
