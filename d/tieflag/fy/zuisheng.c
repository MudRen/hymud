 inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG
����������Ҳ�����ӵİ׾ơ�һ���Ѿ����糶�ѵľ����ϻ���һ���ú�Ȧ����
�ġ��ơ��֡�������ͳ���һ��ҵ�ѱ�ڵİ׷������ײ��·��ż����ƾɵ�ľ����
���ʣ�ľ��������ɢɢ�ط��ż�˫ľ��ͼ������˿ڵ�С������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud5",
]));
        set("objects", ([
        __DIR__"npc/wineowner" : 1,
                        ]) ); 
        set("coor/x",-50);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
