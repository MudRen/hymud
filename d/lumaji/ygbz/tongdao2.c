// zjb /2002/3/15/
inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG
����ص� ��赳����û�г���̦��һ����ϲʪ����ֲ�
�������ǵÿ�������Ϣ����������书���˽���,�϶����
����������Ϣ����!
LONG
        );

        set("exits", ([
                "east" : __DIR__"tongdao2", 
            "south" : __DIR__"tongdao2", 
      "west" : __DIR__"tongdao1", 
    "north" : __DIR__"tongdao3",
                         ]));
set("objects", ([
		__DIR__"obj/corpse" : 1,
	]));                              

        setup();
        replace_program(ROOM);
}

