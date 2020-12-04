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
	      set_name("[32mÌì·ïÖ®·ş×°[2;37;0m", ({ "tianfeng cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[32mÌì·ïÖ®·ş×°[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÁù½ïËÄÁ½ÁùÇ®µÄ[32mÌì·ïÖ®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[31m¾«ÖÂ[2;37;0m [36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [31m»ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;35m·ç[2;37;0m:[35m±ê×¼[2;37;0m 
[1;37mÀ×[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
ÌåÁé:[34mÏ¸Ëé[2;37;0m °×Ê¯:[33mºÜ¸ß[2;37;0m ×ÏÊ¯:[35m±ê×¼[2;37;0m ÉÁµç:[34mÏ¸Ëé[2;37;0m 
ÖÜÌì:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞ¡Âí[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÊÖ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("ownername", "Ğ¡Âí");
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