// Room: /d/jinghai/wm15.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
������Ǿ������鷿�����õ���Ϊ���ţ���������֮�⣬��
���������İ������С�����ϰ��������鼮����ϸ���������
�Ͼ��ǹ����书���顣����ǽ����Щɽˮ�ֻ���ǽ�ϻ�����һ��
������д�š�ѧ��ֹ�����ĸ����ɷ���Ĵ��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"wm9",
	"enter" : __DIR__"mi5",
]));
        set("objects",([
        __DIR__"npc/guan1.c" : 1 ,
        __DIR__"npc/obj/xian-steps_book" : 1 ,	
        __DIR__"npc/obj/bibo-sword_book" : 1 ,	
        __DIR__"npc/obj/jinghai-force_book" : 1 ,			
]));


	setup();
}
int valid_leave(object me,string dir)
{
	object *inv;

        if(!me)
                return 0;

        if(dir == "north" || dir == "n")
        {
                if(sizeof(filter_array(deep_inventory(me),(: $1->is_jinghai_book() :))))
			return notify_fail("����������ס��˵��������կ��֮�������ɵ伮����Я���鷿����\n");
        }

	if(dir == "enter")
	{
		if( (me->query("class") != "jinghai") && !wizardp(me) )
			return notify_fail("������ס��˵�����������صأ����˲������ڣ���\n");

		inv = filter_array(all_inventory(me), (: $1->is_character() :));
		if(sizeof(inv))
			foreach(object n in inv)
				if(!n->move(this_object()))
					return notify_fail("������ס��˵�����������صأ����˲������ڣ���\n");
	}

        return ::valid_leave(me,dir);
}
