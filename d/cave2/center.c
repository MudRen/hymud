 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�˽��͵�����");
        set("long", @LONG
���ﾹ�Ǹ��˽��͵����ӣ��ǰ���ǽ���е��������е��Ǹ֣��е�
��ʯ�壬������һ�����ǽ��ӡ������û�����ӣ�û�г��ӣ���
Ϊ�ڵصף�����Ҳû������������������Ҳ��֪����������ġ�
������ֻ�н��̣����СС����״��ͬ�Ļ���ͳ�̣��е���������
�е���ʯ�죬��Ȼ��Ҳ�е��ǽ��ӵġ� 
LONG
        );
        set("exits", ([ 
                "gold" : __DIR__"gold",
                "silver" : __DIR__"silver",
                "copper" : __DIR__"copper",
                "iron" : __DIR__"iron",
                "tin" : __DIR__"tin",
//              "earth" : __DIR__"earth",
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
