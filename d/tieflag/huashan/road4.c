 inherit ROOM;
void midnight_event();
void sunrise_event();
void create()
{
        set("short", "����·");
        set("long", @LONG
�����澰ɫ��Ȼ��ͬ������������ش������ܳ��������⣬·�Բ�ʱ��һ���
ũ�˿��ѳ�������أ�������ֻ��ɽ������ͦ��һƬ�Դ䣬һ��С��·�ƹ�������
�ѵ����Ϸ���չ��
LONG
        );
    set("exits", ([ 
                "north" : __DIR__"road3",
                "south" : __DIR__"shanmen",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-560);
    set("coor/y",-15);
    set("coor/z",0);
//    NATURE_D->add_day_event(20, 2, this_object(), (: midnight_event :)); 
        setup(); 
}
