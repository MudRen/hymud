 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���Ƿ��Ƴ�����һ���м���һ���������۵Ĺٵ��������Ͷ�����չ��
�����������ǽ���ɳĮ�����������˺ܶ࣬ż������Щʿ����Ѳ�ߵ�
���û�����н�ʨ�ھֵ���ͷ��Ѻ���ڳ���ȥ��Į����Щ�Ӵ˾�û
���ٻ�������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road1",
  "east" : "/d/tieflag/fy/wgate",
  "south": __DIR__"sroad1",
//  "west" : "/d/songshan/dengfeng",
]));
        set("outdoors", "quicksand");
            set("coor/x",-160);
        set("coor/y",0);
        set("coor/z",0);
            replace_program(ROOM); 
        set("coor/x",-160);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}      
