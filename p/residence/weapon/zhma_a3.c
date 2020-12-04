#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[1;37m��������[2;37;0m", ({ "bad armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
��֮����[2;37;0m����һ���ɻ����Ӳ��[32m��ͭ[2;37;0m����[1;37m�޻�[2;37;0m�Ƴɣ�����������Ǯ��[1;37m��֮����[2;37;0m��
�ۺ�����[32m����ϸ��[2;37;0m �����������̣�����[36mһ��[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[36m����[2;37;0m [36mľ[2;37;0m:[31m����[2;37;0m [31m��[2;37;0m:[32m�ֲ�[2;37;0m [1;35m��[2;37;0m:[31m����[2;37;0m 
[1;34m��[2;37;0m:[32m�ֲ�[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[32m�ֲ�[2;37;0m ����:[33mһ��[2;37;0m 
����:[32m����[2;37;0m ����:[33mһ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m���º�[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "zhma");
		set("ownername", "���º�");
		set("value", 2000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 413);
    set("armor_prop/defense", 2);
    
    set("armor_prop/neili", 7);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",1);
    set("wtypeB",6);
    set("wtypeC",0);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",3);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 3);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";