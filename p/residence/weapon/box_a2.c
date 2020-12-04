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
	      set_name("[1;32mÎäÒíÖ®¶Ç´ø[2;37;0m", ({ "wuyi surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[1;32mÎäÒíÖ®¶Ç´ø[2;37;0mÕâÊÇÒ»ÌõÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÎå½ïÈıÁ½°ËÇ®µÄ[1;32mÎäÒíÖ®¶Ç´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;35m¾øÊÀ[2;37;0m [32mË®[2;37;0m:[31m¾«ÖÂ[2;37;0m [31m»ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;35m·ç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÖÜÌì:[34mÏ¸Ëé[2;37;0m ³¤Éú:[33mºÜ¸ß[2;37;0m ²»ÀÏ:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÍò½£´©ĞÄ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("ownername", "Íò½£´©ĞÄ");
		set("value", 16000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 45);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 253);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 23);
    set("armor_prop/qi", 47);
    set("armor_prop/jing", 39);
    set("armor_prop/jingli", 39);
    set("armor_prop/damage", 181);

    set("wtypeA",0);
    set("wtypeB",11);
    set("wtypeC",6);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",8);
    set("wtypeG",3);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "strike",
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