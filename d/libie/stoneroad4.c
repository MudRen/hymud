 // Room: stoneroad.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "ʯ��·"); 
        set("long", @LONG
С�س��б�ֻ��һ��ʯ��·�ɹ�·��������·��������������
�м����˼ң�ʯ������̦���̣�һ��С�ı��ˤ����ͷ��Զ����һ
Ƭ÷�֣�������Ʈ�����������޵�÷�ӳ����ζ����  
LONG); 
        set("type","road");
        set("exits",([
    "west":__DIR__"stoneroad3",
    "northeast":__DIR__"brook",
        ]) );
        //}}
        set("outdoors", "libie");
        set("coor/x",60);
        set("coor/y",200);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}     
