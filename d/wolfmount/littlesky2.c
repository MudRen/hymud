 inherit ROOM;
void create()
{
    set("short", "һ����"); 
        set("long", @LONG
��·���ˣ�ɽ·������ö����ޱȣ����������ͱڸ߸߱������м�ֻ����һ��
խխ��ɽ·���������˲��ܲ�����У�̧ͷ��ȥ��ֻ��һ�ߵ���գ�����м�ֻɽ
ӥ�����ɹ�������
LONG); 
        set("exits",([
        "eastup":__DIR__"moonrock",
        "westdown":__DIR__"littlesky3",
        ]) );
       set("outdoors", "wolfmount");
        set("coor/x",-620);
        set("coor/y",-710);
        set("coor/z",90);
        setup();
        replace_program(ROOM);
}    
