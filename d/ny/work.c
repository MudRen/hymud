
// work.c

inherit ROOM;

void create()
{
        set("coor",({1000,4700,10}));
	set("short", "ɹ�ȳ�");
        set("long",
"����һ��ɹ�ȳ������ֿ���Ĺ��ӷ�����̯ɹ�ĵط����׳��ϰ���һ��һ����֪����ʮ�־�\n"
"���ĸ��ݵ������ˣ����Ǵ���һ����Ц������Կ������������ææµµ�Ĺ����ţ��ſڹ�\n"
"��һ������(sign)��������ͨ����Զ�ǵĴ�·��\n"
);
        set("exits", ([ /* sizeof() == 1 */
     "northwest" : __DIR__"temple",
     "south" : __DIR__"road11",
]));

        set("item_desc", ([
                "sign": @TEXT
��������ȱ���֣������Ӷһ���̹����ɻ

work     ��ʼ������

TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
 set("outdoors", "ny");
        setup();
}

void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();
   if (me->is_busy())
        return notify_fail("���������ڸɻ�ɣ�\n");

   if (me->query_temp("times")>20)
        return notify_fail("����Ļ�����ˣ����������ɣ�\n");
        if( me->query("jing")<=29||me->query("qi")<=29)
        {  message_vision("$N����̫����,�������������ɡ�\n",me);
           return 1;
         }
message_vision("$N����Ĺ������ڽ����ˣ�����Ҳ�۵�Ҫ��\n", me); 
me->add("jing",-30);
me->add("qi",-30);
me->add_temp("times",1);
//receive_damage("gin",30,me);
//receive_damage("sen",30, me);
ob = new("clone/money/silver");
me->start_busy(15);
ob->move(me);
message_vision("�ϰ��$N˵��������Ĺ�Ǯ��\n", me);
return 1;  
}
