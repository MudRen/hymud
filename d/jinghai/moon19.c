// Room: /d/jinghai/moon19.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����ˮկ���鷿��ŵĴ󲿷��Ǳ��飬���ﲻ���кܶ�ĳ�
���ں����������ǰ���������ĺ�ս�ĵã�Ҳ��һЩ½ս�ֲᣬ
������Ҫ�����ҵ��������鼮�ͺ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"moon8",
]));
        set("objects",([
        __DIR__"npc/guan2" : 1,
        __DIR__"npc/obj/xian-steps_book.c" : 1 ,	
        __DIR__"npc/obj/bibo-sword_book.c" : 1 ,	
        __DIR__"npc/obj/jinghai-force_book.c" : 1 ,		
]));


	setup();
}


int valid_leave(object me,string dir)
{
        if(!me)
                return 0;

        if(dir == "west" || dir == "w")
        {
                if(sizeof(filter_array(deep_inventory(me),(: $1->is_jinghai_book() :))))
                        return notify_fail("����������ס��˵��������կ��֮�������ɵ伮����Я���鷿����\n");
        }

        return ::valid_leave(me,dir);
}

