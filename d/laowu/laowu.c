 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ա������ɻ���֮�ϣ��������ֵ���˼���ǡ����ݡ�������������Ȼ����
�����ۺ����У���ʵȴ�Ǹ���Ƨ������ĵط���ÿ������ǰ�󣬾Ϳ�ʼ�⽭��ֱ����
����������Žⶳ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"town",
  "south" : __DIR__"road5",
]));
        set("outdoors", "laowu"); 
        set("coor/x",0);
        set("coor/y",12020);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}    
