 inherit ROOM;
void create()
{
        set("short", "�����ķ�");
        set("long", @LONG
�����ķ����ú�������������ů�ͻ��֣������л�����ϵ�֬�۵���������Ǯ
�û�������һ��������ö������������伸��û���κ�һ�������ܱȵ��ϡ�������
��ʵ���Ǹ����ݳ޵ĵط�����ʱ����Ϊ��ʽ�����ݳ޵��ˣ�׼���Ÿ�ʽ�����ݳ޵�
���ܡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/tieflag/fy/swind3",
  "west" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/xiazi" : 1,
        __DIR__"npc/daniu": 1, 
                        ]) ); 
        set("coor/x",-10);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
