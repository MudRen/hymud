// xiaoting.c С��
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
������һ��СС�����ã�Ҳ����Ϊ������ǰ���������õġ�����
�������Χ�Ĺ�������һЩ���㷢������ȼ����һЩ�͵ơ������
�������������ª��һ��һ�ζ���ʰ�ľ���������
LONG
        );

        set("exits", ([
                "south" : __DIR__"zhengting",
                "north" : __DIR__"qianting",
                "west" : __DIR__"xiaowu1",
                "east" : __DIR__"xiaowu2",
        ]));
set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");        
        set("objects", ([
           __DIR__"npc/gumudizi" : 2,
           "quest/menpai/gumu/shi" : 1,
                   ]));

        setup();
        replace_program(ROOM);
}
