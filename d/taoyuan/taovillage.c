 inherit ROOM;
void create()
{
        set("short", "��Դ��");
        set("long", @LONG
��ǰ��Ӱɽ��֮�£������ɢ���ż������ᣬ�������������޺ۣ�ż��Ȯ�ͣ�
Ҳ�ܿ����ƽ�����������о������κγ��������ӣ�һ�ж��������İ�������
�������棬Ҳֻ����������ݷ��㣬��Զɽ���䡣һ���򵥵�ľդ������������
����·�ϣ�һ����ɫ��ʯ��·�����ѵ���չ��ȥ��·�ߴ�����һ��޴��ɽʯ��
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
    "east" : __DIR__"road1",
        ]) );
        set("objects", ([
                __DIR__"obj/stone": 1,
        ]) );
        
        set("item_desc", ([
                "gate" : "�򵥵�ľդ���Ű����ţ������衡�����壩��\n",
                "door" : "�򵥵�ľդ���Ű����ţ������衡�����壩��\n",
                "դ����" : "�򵥵�ľդ���Ű����ţ������衡�����壩��\n",
        ]) );
                set("outdoors","taoyuan");
        set("coor/x",180);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
}  
void pipe_notify()
{
        object  room;
        
message_vision("�����������Եĸ��������������\n", this_player());
        call_out("animal_come", 3);
} 
void animal_come()
{
        object deer; 
        deer = present("little deer", this_object());
   if(!objectp(deer)) {
                deer = new(__DIR__"npc/deer");
                deer->move(this_object());
message("vision","����δ�䣬һֻС÷��¹�ʹ����Ժ����˳�����\n", this_object());
        }
} 
//int init_enter(object ob) {
//   write("\n\nLEAVE LEAVE LEAVE!\n");
//   return 0;
//} 
void init() {
        add_action("do_push", "push");
}  
void close_path()
{
        if( query("exits/northwest") ) {
    message("vision","դ������������Զ����ϡ�\n",this_object() );
    delete("exits/northwest");
    }
} 
int do_push(string arg)
{
        object me;
    me = this_player();
    if( arg=="door" || arg =="դ����" || arg == "gate") {
        message_vision("$N�����ڵ�դ������һ�ƣ���֨֨��������һ��դ���Ŵ��ˡ�\n", me);
                set("exits/northwest", __DIR__"fenghuo");
                call_out("close_path", 5);
        }
        else {
                write("��Ҫ��ʲô�أ�\n");
        }
        return 1;       
 }
