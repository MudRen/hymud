inherit ROOM;
void create()
{
        set("short", "�޻���");
        set("long", @LONG
ÿ���������䣬�������ٶ��ᵽ��������Լ��Ķ�����������һ�����������
������Ƴ����·������������·������ι̣���������ǡ���ô�����仨�������
��ʲô�ģ�һ���Ҳ�����������ĺۼ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud4",
]));
        set("objects", ([
            __DIR__"npc/mianhua" : 1,
                        ]) ); 
        set("coor/x",40);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
