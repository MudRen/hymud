 inherit ROOM;
void create()
{
                object silver;
        set("short", "�����");
        set("long", @long
��������һƬ����Ǭˬ��������Ȼ�������˰��˺ܶණ����������Ȼ��
�úܿ������ϻ���һЩʪ�����Ľ�ӡ����Ȼ��������������żȻ�������һ
����Ӱ��Ҳ�����û̿֡������ƺ��Ե��ϵı��ﲢ��̰����ֻȡȥ�Լ����裬
�������뿪��
long
        );
        set("exits", ([ /* sizeof() == 4 */
"out" : __DIR__"snewbie2",
  "enter" : __DIR__"snewbie4",
  
]));
        set("objects", ([
 
"/d/quicksand/npc/obj/jade3":1,
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",0);
        set("coor/y",-30);
        set("coor/z",-10);
        
        setup();
  

}
