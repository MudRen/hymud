 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "����");
        set("long", @LONG 
�˴�����Ϊ�֣�ȴֻ��һ��˶���ޱȵĿտ�ʯ�ң����滷ɽ����ʯ���汻��ĥ��
ʮ�ֹ⻬�����ǰ��Ƴǵ��ӳ�Ϧ����ϰ��֮�������Ƴ�����Ϊһ�������ѣ���������
֮�ˣ��������µ���ϰ��Ҫ���ϣ���˰��Ƴǵ��ӽԿ̿�������������˿���Ͷ裬
����ʯ���ϲ����˸�ʽ�������۵ĳ��������Ƴ�����ν�����ڽ�ʿ����νʮָ���ġ�
������۵ķϽ���ҲҪ���ƴ��á��˴���Ϊ���֣�ʵΪ��ڣ��
LONG 
           ); 
        set("exits",  
           ([  
       "northwest" : __DIR__"jintaoting",
       "southup" : __DIR__"guajianbei",
       "westdown" : __DIR__"qianlonghu",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/jiannu" : 1,
       __DIR__"obj/junksword" :3,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1720); 
        set("coor/z",10); 
        setup(); 
        replace_program(ROOM); 
}       
