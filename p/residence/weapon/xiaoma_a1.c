#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[32m���֮��װ[2;37;0m", ({ "tianfeng cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[32m���֮��װ[2;37;0m����һ�����ޱȼ�Ӳ��[1;33m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ�������������Ǯ��[32m���֮��װ[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȼ�̣�����[35m�������[2;37;0m�ķ�������
������˼����ŷ��ţ�
[40m��[2;37;0m:[31m����[2;37;0m [36mľ[2;37;0m:[35m��׼[2;37;0m [31m��[2;37;0m:[31m����[2;37;0m [1;35m��[2;37;0m:[35m��׼[2;37;0m 
[1;37m��[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��˫[2;37;0m ����:[33m�ܸ�[2;37;0m 
����:[34mϸ��[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ��ʯ:[35m��׼[2;37;0m ����:[34mϸ��[2;37;0m 
����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mС��[2;37;0m ������һЩ�� [1;32m�ַ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoma");
		set("ownername", "С��");
		set("value", 16000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 44);
    set("armor_prop/parry", 55);
    set("armor_prop/attack", 20);


    set("armor_prop/armor", 479);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 41);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 117);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",6);
    set("wtypeF",5);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",6);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";