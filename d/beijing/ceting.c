inherit ROOM;

string* books = ({
        "/clone/book/yljing",
        "/clone/book/yljing1",
        "/clone/book/yljing2",
//      "/clone/book/yljian",
//      "/clone/book/ylbian",
        "/clone/book/book-bamboo",
//      "/clone/book/book-paper",
        "/clone/book/book-silk",
        "/clone/book/book-stone",
        "/clone/book/book-iron",
        "/clone/book/quanpu",
        "/clone/book/dujing_1",
});


void create()
{
	set("short", "����");
	set("long", @LONG
�����ǲ�������ǽ��һ����ܣ������˸���ȭ�ס��鼮��ǽ����һ
��ľ������ػ��ܶ����½��ϳ�����������顢��Ϣ��
LONG );
	set("exits", ([
		"west" : __DIR__"dating",
	]));
        set("sleep_room", 1);   
	set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");        
	set("objects", ([
            "quest/menpai/yunlong/shi" : 1,
		__DIR__"npc/yldizinew" : 3,
		"/d/beijing/obj/tiandiling" : 2,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
