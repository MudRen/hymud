 inherit ROOM;
void create()
{
        set("short", "����ǽ");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"necorner",
  "south"  : __DIR__"eupgate", 
]));
        set("outdoors", "fengyun");
        set("coor/x",60);
        set("coor/y",30);
        set("coor/z",30);
        set("coor/x",60);
        set("coor/y",30);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}       
