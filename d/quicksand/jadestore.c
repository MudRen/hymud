 inherit ROOM;
void create()
{
        set("short", "�鱦��");
        set("long", @LONG
����һ���ƾɵ�С�ꡣר�ž�Ӫ������������������Ƨ�������С���
����ȴ�ر�á�Ҳ���ǳ������˶�֪�������ն�����׶༪�٣�������
�����������֡�
LONG
        );
        set("exits", ([ 
 "south" : __DIR__"saikou",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/jadeowner" : 1,
        ]) ); 
        set("coor/x",-1030);
        set("coor/y",10);
        set("coor/z",0);
        setup(); 
}   
