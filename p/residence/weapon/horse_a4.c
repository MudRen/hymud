#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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
	      set_name("[35mÌìÁúÖ®¶Ç´ø[2;37;0m", ({ "tianlong surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[35mÌìÁúÖ®¶Ç´ø[2;37;0mÕâÊÇÒ»ÌõÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[32mÓñ²ÏË¿[2;37;0mÖÆ³É£¬ÖØ¶ş½ïËÄÁ½ËÄÇ®µÄ[35mÌìÁúÖ®¶Ç´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[31m¾«ÖÂ[2;37;0m [33mÍÁ[2;37;0m:[33mºÜ¸ß[2;37;0m [1;35m·ç[2;37;0m:[1;31mÎŞË«[2;37;0m 
[1;37mÀ×[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
×ÏÊ¯:[34mÏ¸Ëé[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
²»ÀÏ:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞ¡Âí[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÈ­½Å[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "horse");
		set("ownername", "Ğ¡Âí");
		set("value", 16000);
		set("armor_prop/intelligence",34);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",20);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 23);
    set("armor_prop/attack", 55);


    set("armor_prop/armor", 159);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 32);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 69);

    set("wtypeA",0);
    set("wtypeB",6);
    set("wtypeC",3);
    set("wtypeD",0);
    set("wtypeE",4);
    set("wtypeF",12);
    set("wtypeG",11);
    set("wtypeH",7);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",2);
    
    
                set("skill", ([
                        "name": "unarmed",
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