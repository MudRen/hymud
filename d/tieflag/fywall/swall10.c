 inherit ROOM;
void create()
{
        set("short", "�ϳ�ǽ");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"supgate",
  "west"  : __DIR__"swcorner", 
]));
        set("outdoors", "fengyun");
        set("coor/x",-30);
        set("coor/y",-60);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}
