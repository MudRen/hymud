 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ӳ��õþ���������뷿�����Ե���ױ̨�ϣ���Ȼ����������
����ױ�þߣ������滹�и���Ͱ���ƿ����ӣ�����ֱֱ�����ž���
�ã����١����壬����������������ͷ�ϣ���Ȼ�Ǹ�Ů�ӡ� 
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"silver",
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
