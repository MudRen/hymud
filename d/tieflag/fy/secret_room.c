 inherit ROOM;
void create()
{
        object silver;
        set("short", "��������");
        set("long", @LONG
������һ��խС�����ң������ǰֻ��һ���ƾɵ�С����һЩǬ�ݡ�
LONG
        ); 
        set("objects", ([
                "/d/tieflag/fy/obj/biaoyin": 1
        ]) ); 
        set("coor/x",20);
        set("coor/y",50);
        set("coor/z",-10);
        setup();
        silver = present("biaoyin",this_object());
    silver->set_amount(random(1000)+1000);    
        //silver->set("name", "����");
}      
