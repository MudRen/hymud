 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�ص�����������ͷ����һ���ţ�������Ҳ�����һЩ���ﻨ�ݣ�
��������ֻ�������ص����Ͳ�֪���˶��������������������
�˿ϻ���ô������������ڵ��½������ߵ������治֪�Ǹ�ʲ
ô���Ĺ���ź��棬��һ�������ص�������˻�����������
Ȼ���ûʣ��ڵ��¾���������ûʵ����ã����Ǽ������벻��
���¡�����û�д��ӣ������ֱ�͵��ϸ����Ļ���ûʲô������
��������´󷽣������й�֮�� 
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace4",
                "south" : __DIR__"palace2",
                "west" : __DIR__"bedroom1",
                "east" : __DIR__"corridor1",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
