inherit ITEM;


void create()
{
        set_name("ʯ������", ({ "qi pan", "pan" }));
        set("long","����һ����ھ�ʯ�ϵ����̣��������һЩ���ӡ�\n");
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);              
                set("no_get","���������ֱ�ӿ�����ʯ�ϵģ��޷���ȡ��\n");
                set("qizi",2);
        }
}

void init()
{
        add_action("do_get","get");
}

int do_get(string arg)
{
        object ob;
        string qizi,qipan;
        ob = this_player();
        if(arg == "qi pan" || arg == "pan" )
        {
                tell_object(ob,"���������ֱ�ӿ�����ʯ�ϵģ��޷���ȡ��\n");
                return 1;
        }
        if(sscanf( arg, "%s from %s", qizi, qipan)!=2)return 0;
        if((qizi !="qi zi" && qizi !="zi")
        ||(qipan!="qi pan" && qipan != "pan") )return 0;
        if(present("yi zhe",environment(this_object()) ) )
        {
                tell_object(ob,"�����������壬��ô�ܰ����������أ�\n");
                return 1;
        }
        if(query("qizi") <= 0 )
        {
                tell_object(ob,"�����Ѿ��������ù��ˡ�\n");
                return 1;
        }
        message_vision("$N������������һ�����ӡ�\n",ob);
        add("qizi",-1);
        new(__DIR__"qizi")->move(ob);
        return 1;
}
