 // Room: 18.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��Ժ"); 
        set("long", @LONG
���Ǽ�ܿ���Ժ�ӣ����ƺ����������������ҳ���أ���������Ժ��������
��һƬ����ɫ������ȴҲ��֪���̣�������
LONG);
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "north":__DIR__"fodian",
        "south":__DIR__"fanyinshi",
        ]) );
        set("outdoors", "shanliu");
        set("coor/x",-97);
        set("coor/y",-595);
        set("coor/z",60); 
        //}} 
        setup();
        replace_program(ROOM);
}   
