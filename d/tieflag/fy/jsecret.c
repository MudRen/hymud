 inherit ROOM;
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
����������ˮ�������ˮ�ж��ż�����׮��׮���о��ֻ������������ѹ����
�ġ�ż������ˮ��ð��ˮ�棬������Ѫĭ�����ݵ÷��׷����Ķ�֫�����м���׮������
����������ż�����Ŀ���������á�һ�Ѱװ����ֵ����ڻ��������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"tang3",
]));
        set("objects", ([
        __DIR__"npc/xongyang": 1,
                        ]) );
        set("coor/x",-20);
        set("coor/y",0);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
} 
