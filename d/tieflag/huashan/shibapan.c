 inherit ROOM;
void create()
{
        set("short", "ʮ����");
        set("long", @LONG
�˴�ɽ�ƶ��ͣ���ɽ��·���ͼ�����·��ɽ�������̻���ʮ�а�����ɽ���ϣ�
·�Ծ����������㲻ʱ�ı�����ǣ���¹ڡ�
LONG
        );
    set("exits", ([ 
                "northeast" : __DIR__"shaluo",
                "southeast" : __DIR__"shibapan1",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-580);
    set("coor/y",-50);
    set("coor/z",40);
        setup();
} 
void init(){
        object me, jingji, obj;
        me = this_player();
        if(me->query("����B/��Դ_����") && !present("jingji", this_object())) {
                jingji = new(__DIR__"obj/jingji");
                jingji->move(this_object());
                obj = new(__DIR__"obj/book");
                obj->move(jingji);
        }
}     
