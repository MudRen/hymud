// shuijing.c

inherit ROOM;
void create()
{
        set("short","ˮ��");
        set("long",@LONG                                   
������һ����ʯ�̾͵ľ�̨���Ŀ���ʯ����ɾ����͡���ʯ
������ˮ���˵Ľ�̤��һ��������㼣������������һ��ҪС�ģ�
�ɲ�Ҫˤ����
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu5",
               "east" : __DIR__"xiaolu6",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
