 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG 
�˴�����ïʢ����������͸�����ܵ���Ҷ�ƺ���Ⱦ���˵�������ɫ��������� 
�������ˣ��紵�񶯣����µ���Ҷ����ɳɳ�����죬������Ʈɢ��һ�ɼ����Ŀ�ɬ 
ζ��������ϸ���ѷֱ�ĳ�����     
LONG
        ); 
        set("exits", ([ 
                "southeast" : __DIR__"jiulong", 
                "northdown" : __DIR__"kuzhu",
        ]));
    set("outdoors", "huangshan");
    set("coor/x",-560);
    set("coor/y",-470);
        set("coor/z",20);
        setup();
} 
