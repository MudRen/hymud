 // Room: nongjia.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "é��"); 
        set("long", @LONG
�سǲ�ͷ����������˼�С�ݣ��������ڣ��Դ������������
��һ��������Ů�����ò���Ư������ȴ�������ᡣ���һ��û�л�����
���ͻἱ�ö㵽ϴ�·���СϪ��ȥ͵͵���ᡣ�����һ�ж����ˣ���
��������ģ�����׹��������������ֻ������Ϊ��������һ�У�����
��Ϊ���׷����һ������Ϯһ�Ⱥ���������Ľ��ڴ󰸡�
LONG); 
        set("type","indoors");
        set("exits",([
        "east":__DIR__"yard",
        ]) ); 
        set("objects", ([
                __DIR__"obj/coffin": 1,
        ]) );
        set("indoors", "libie");
        set("coor/x",43);
        set("coor/y",210);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}    
