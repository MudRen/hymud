 inherit ROOM;
void create()
{
        set("short", "�ƺ�����");
        set("long", @LONG
�ƣ������ڽ��£����ˣ�������ˮ����������һ��
����֮�����ƺ���Ư�����ֲ�����ˮ�������Ǵ����ߡ����ߣ�
���ճ�֮�ߣ����Ǵ�˵�еġ������ȡ���
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"entrance",
  "eastup" :    __DIR__"palace_gate",
  "westdown" : __DIR__"palace_path3",
]));
        set("outdoors", "palace"); 
        set("coor/x",130);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",130);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",130);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",130);
        set("coor/y",0);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}   
