//Writen by lnwm
//maowu.c
inherit ROOM;

void create()
{
        set("short", "Сé��");
        set("long", @LONG
һ���ª��Сé��,���еĳ���򵥶��¾�.����������һ���ƺ�����
�Ĳ��õ�С����Ϸ���һֻ�ѱ���Ѭ�÷��ڵĹ���������һ��������һ
�Ŵ�,��������һ������.���˿����������ֻ΢΢����һ���ۣ����ֱ���
��,һ�仰��û˵.
LONG
        );
        set("exits", ([
            "southwest"     :       __DIR__ "lroad5",
                ]));
        set("objects", ([               
                 __DIR__ "npc/laoren": 1,
                ]) );
        setup();
}

void init()
{
        add_action("do_medicine",({"��ҩ","����","make","make medicine"}));
}

int do_medicine()
{
        object ob1,ob2,ob3,ob4,ob5;
        object me;
        me = this_player();
        ob1 = present("luo bu",me);
        ob2 = present("jiang",me);
        ob3 = present("tang kuai",me);
    ob4 = present("gou qi",me);
        ob5 = present("lajiao you",me);

        if( ob1 && ob2 && ob3 && ob4 && ob5)
        {               
        message_vision("
\n$Nϸϸ�ؽ������г���ĩ���Ž����ڡ��ټ����ܲ�����ǣ�����ˮ���ӻ���������\n",me
                );
        destruct(ob1);
        destruct(ob2);
        destruct(ob3);
    destruct(ob4);
    destruct(ob5);
        call_out("give_medicine",random(5)+1,me);
        return 1;
        }
        return 0;
}

int give_medicine(object me)
{
        object medicine;
        if(me) 
        if(environment(me) == this_object())
        {
        medicine = new( __DIR__ "obj/jiangt");
        if(medicine->move(me))
        message_vision("
\n$N�ӹ���Ҩ��һ���������ڵĽ���\n",me);
        }
        return 1;
}

