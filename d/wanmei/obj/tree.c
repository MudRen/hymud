 inherit COMBINED_ITEM;
void create()
{
        set_name("÷������", ({ "tree", "plum tree" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","������������磬Ҳ������������죨����壩Щ������\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 10000);
                set("base_value", 1);
        }
        set_amount(1);
    
}
void init()
{
    if(this_player()==environment()) {
        add_action("do_make","make");
    }
} 
int do_make()
{
        object boat; 
        if(this_player()->query("str") < 16)
        return notify_fail("����С�������޷����Сľ�ۡ�\n");
        if(query_amount() < 15)
        return notify_fail("��"+chinese_number(query_amount())+
        "��÷�����磬ʲôҲ�첻��ѽ������\n");
        if((int)this_player()->query_encumbrance() + 150000 > (int)this_player()->query_max_encumbrance())
        return notify_fail("��ĸ���̫���޷����Сľ�ۡ�\n");
        seteuid(getuid());
        boat = new(__DIR__"boat");
        if(boat->move(this_player())){
        message_vision("$N�����ɵ�˫�������һֻСľ�ۡ�\n", this_player());
        }
        if(!this_player()->query("m_success/ľ��"))
        {
                this_player()->set("m_success/ľ��",1);
                this_player()->add("score",150); 
        }
        destruct(this_object());
        return 1;
                        
}       
