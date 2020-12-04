#include <ansi.h> 
#include <armor.h>

inherit NECK;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;32m�޼�֮����[2;37;0m", ({ "wuji neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;32m�����Ѵ�����뻯���Ƿ��켫���������֮���磡��˵������ڣ������⡰�޼�����
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ������������Ǯ��[1;32m�޼�֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;35m����[2;37;0m [32mˮ[2;37;0m:[1;32mħ��[2;37;0m [31m��[2;37;0m:[1;33m��ʥ[2;37;0m [1;35m��[2;37;0m:[1;33m��ʥ[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[34mϸ��[2;37;0m ����:[1;36m����[2;37;0m 
��ʯ:[33m�ܸ�[2;37;0m ��ʯ:[34mϸ��[2;37;0m ����:[31m����[2;37;0m 
����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�򽣴���[2;37;0m ������һЩ�� [1;32m�ȷ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "box");
		set("ownername", "�򽣴���");
		set("value", 25000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",25);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 25);
    set("armor_prop/attack", 66);


    set("armor_prop/armor", 376);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 248);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",9);
    set("wtypeD",10);
    set("wtypeE",1);
    set("wtypeF",10);
    set("wtypeG",3);
    set("wtypeH",0);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";