 inherit ROOM;
void create()
{
        object con, item; 
        set("short", "ũ��");
        set("long", @LONG
���������������ڿ���һ�ˡ����ڰ���ǳ����ӣ�ֻ�м�������
����Ʒ��������ǽ�Ϲ�����һ������������İ��輫�䲻�͡��㲻��
��ʼ����������˵�������ݡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"xzroad3",
        ]));
        set("objects", ([
                __DIR__"obj/wall": 1,
        ]));
        set("coor/x",90);
        set("coor/y",-60);
        set("coor/z",0);
        setup();
} 
void reset()
{
        object          *inv;
        object          con, item;
        int             i; 
        ::reset();
        con = present("wall", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword2");
                item->move(con);
        }
}   
