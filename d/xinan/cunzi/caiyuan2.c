//writen by lnwm
//caiyuan2.c

inherit ROOM;
void create()
{
    set("short", "��԰");
    set("long", @LONG
��԰�еĲ˵��������˸����߲ˡ�ÿһ�ֶ�����ϲ�ˣ���Ȼ���˾���
�չˡ���¢֮�仹���˹����ѵ�С������������ˮ���ʶ����������ÿ
һ�����硣�����ڶ����ɣ���Ȼ������ׯ��������
LONG
        );
    set("exits", ([ 
                "northeast"     :       __DIR__ "lroad3",
        ]));
    set("item_desc", ([
                "�˵�"  :        "�˵��������˸��ָ������߲ˣ��д��̵��㶹��������ܲ���
                                  ���ĺ����������̲�ס��ժ������\n",

        ]) );
    set("outdoors","lnwm");
    setup();
}

void init()
{
        add_action("do_chop","zhai");
        add_action("do_chop","pull");
        add_action("do_chop","ժ");
}

int do_chop(string arg)
{
    object me;
        object vege;
    if(!arg || arg=="")
    {
        write("��Ҫժʲô��\n");
        return 1;
    }
    if( arg == "�ܲ�" || arg == "luob" )
    {
        if((int) query("pluob") <= 3)
        {
                me = this_player();
        message_vision("$N�ӵ���γ���һֻ���ܲ�\n", me);
                vege = new(__DIR__"obj/luob");
                vege->move(this_player());
                add("pluob",1);
                return 1;
                }
                else
        write("�ܲ��Ѿ����˰ι���\n");
        return 1;
    }
    else if( arg == "�㶹" || arg == "wandou" )
    {
        if((int) query("pwandou") <= 10)
                {
                me = this_player();
        message_vision("$N�ӵ���ժ��һ���㶹\n", me);
                vege = new(__DIR__"obj/wandou");
                vege->move(this_player());
                add("pwandou",1);
                return 1;
                }
                else
        write("�㶹�Ѿ�����ժ����\n");
        return 1;
    }
    else if( arg == "����" || arg == "������" || arg == "lajiao" )
    {
        if((int) query("plajiao") <= 10)
                {
                me = this_player();
        message_vision("$N�ӵ���ժ��һֻ�������\n", me);
                vege = new(__DIR__"obj/lajiao");
                vege->move(this_player());
                add("plajiao",1);
                return 1;
                }
                else
        write("�����Ѿ�����ժ����\n");
        return 1;
    }
    else
    {
        write("�㲻����ժ"+arg+"\n");
        return 1;
    }
}
        
void reset()
{
        :: reset();
        delete("plajiao");
        delete("pluob");
        delete("pwandou");
}

