 inherit ROOM;
void create()
{
        set("short", "һƷ��");
        set("long", @LONG
�����Ǹ��ص����裬����ˮ�Ǵӷ�ҶȪר�̼��������ĺ����������ɰ����
���ķ���Ҳ������ģ�ÿ����ĵ�һ�������������ġ������������Ĳ趼��
һ�ִ����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind3",
  "up" :   __DIR__"yitea2",
]));
        set("objects", ([
        __DIR__"npc/teawaiter" : 1,
                        ]) ); 
        set("coor/x",10);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
