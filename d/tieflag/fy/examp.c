 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ƴ��˲ű�����������־�ڻ�;�ķ��������˶�Ҫ������ͨ����һ�ο��ԡ�
����˫ȫ��ǰ�����ᱻ���뾩�����ԡ����Ƶ���һ����������ӳ�����ÿ��һ��һ
�ȵĿ���������ͻ���ɽ�˺��������ֵıȲο��Ļ��ࡣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud1",
]));
        set("objects", ([
        __DIR__"npc/kaoguan" : 1,
        __DIR__"npc/student" : 3,
                        ]) ); 
        set("coor/x",-10);
        set("coor/y",-1);
        set("coor/z",0);
        setup();
}      
