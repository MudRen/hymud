 inherit ROOM;
void create()
{
        set("short", "�Ϸ����");
        set("long", @LONG
���������ſ���ȸ����һ��ҹ���ͳ�ˮ���������ֵó��˲�ҹ֮���������
ǧ��¥�����Ժգ���Բǧ�����Ǯ�˶�Ը�⵽������һ��ǧ�𣬾�����ûǮ����С
��Ҳ������û����תת��ϣ��һ��¥�����ķ��ݡ�ǧ��¥Ϊ�˷�����ˣ����ڶ�
�濪��һ��ǧ�����̡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind5",
  "north" : __DIR__"swind3",
  "east" : __DIR__"qianyin",
//  "west" : AREA_QIANJIN"qianjin",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
