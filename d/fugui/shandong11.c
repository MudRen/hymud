 inherit ROOM;
void create()
{
        set("short", "��ھ�����"); 
        set("long", @LONG
������ã������������˴˴������Ȼ���ʣ��ѿ�վֱ�������㶨��һ�ƣ�
������ʧɫ�����л�Ȼ�����������ɣ�����ˮͰ�Ľ�ھ����������У�һ�Ա���
��棬˸Ȼ�Ź⡣���к��Ǳ�أ��ȳ��쳣���������
LONG);
    set("indoors", "fugui");
        set("type","mountain");
        set("exits",([
                "south":__DIR__"shandong",
        ]) );
        set("objects", ([
                __DIR__"npc/bigsnake" : 1,
//              __DIR__"obj/skeleton" : 2,
        ]) ); 
        set("coor/x",-610);
        set("coor/y",300);
        set("coor/z",80);
//      set("refresh_all_items", 1);
        setup();
}  
void reset() {
        string item= "skeleton";
        int num = 2;
        object obj, *inv;
        
        :: reset();
        
        inv = all_inventory();
        foreach (object ob in inv) 
        {
                if (userp(ob)) continue;
                if (ob->query("id") == "bone") destruct(ob);
        }
        while (num--) 
        {
                obj = new(__DIR__"obj/"+item);
           obj->move(this_object());
        }
}      
