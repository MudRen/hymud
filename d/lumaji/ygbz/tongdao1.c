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
                "south" : __DIR__"tongdao2",
                "out" : __DIR__"jindi",
                         ]));

        setup();
        replace_program(ROOM);
}

