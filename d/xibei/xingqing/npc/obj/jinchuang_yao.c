inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_use", "use");
}
void create()
{
        set_name("��ҩ", ({"jinchuang yao", "jin", "jinchuang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ʿ�ر��Ľ�ҩ��\n");
                set("value", 6000);
        }
        setup();
}
int do_use(string arg)
{
        if (!id(arg)) 
                return notify_fail("��Ҫ��ʲôҩ��\n");
        if ( this_player()->query_condition("jin-chuangyao"))
                return notify_fail(
"���Ѿ����Ͻ�ҩ�ˡ�\n");
        if ((int)this_player()->query("eff_kee") ==
            (int)this_player()->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
        else {
                message_vision("$N�ѽ�ҩ�����˿��ϡ�����������\n", this_player());
                if( this_object()->query("usetime") >10)
                           destruct(this_object());
                else
                           this_object()->add("usetime",1);
                this_player()->apply_condition("jin-chuangyao",8);
                return 1;
        }
}

