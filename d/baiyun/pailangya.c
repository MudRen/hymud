 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "������");
        set("long", @LONG 
�������β��ϵس������ʯ���˻��ɽ�������������֮�£�����ǧ���⣬Զ��
Ҳ�ǹ�����㣬�����޼ʣ�εΪ��ۡ��쪵ĺ������ʯ�����˵����ǣ�����������
��������뺣��Լ������ʮ�ɣ����Ǹ��ͣ������仹�и��ߵ���ʯ�ͱڣ���������վ
����һ��޴����ʯ��֮ʱ���������ϵĸ��Ʊ������֮�⣬����ŸҲ���ٷ�������
�����Ŵ󺣡��˻�����Ÿ�������к��鼤������Ѫ��С�;
LONG 
           ); 
        set("exits",  
           ([  
       "southup" : __DIR__"jintaoting",
       "northwest" : __DIR__"baiyunentrance",
       "east" : __DIR__"shiliang",
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1710); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}  
